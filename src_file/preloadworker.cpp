#include "../include/preloadworker.h"


PreLoadWorker::PreLoadWorker(){
    g_is_page_current_changed = false;
    g_is_preload_run = false;
    //parallelLoadPage();
}

void PreLoadWorker::loadAndCacheImage(const int page_num, const int page_type){
    //check if it already exists
    ImageData* image_data_ptr;
    cache_lock.lockForRead();
    if(cache.contains(page_num)){
        image_data_ptr = cache.object(page_num);
        if(image_data_ptr->page_type == page_type){
            cache_lock.unlock();
            return ;
        }
    }
    cache_lock.unlock();

    //if it dosent exist
    image_data_ptr = new ImageData;
    image_processor.getImage(page_num, page_type, *(image_data_ptr->cv_image_ptr));
    image_data_ptr->page_type = page_type;
    cache_lock.lockForWrite();
    cache.insert(page_num,image_data_ptr);
    cache_lock.unlock();
}

void PreLoadWorker::parallelLoadPage() {//using extern preload_params
    // boucle infinie 
    while (1) {

        // La fonction attend que la condition spécifiée par la variable conditionnelle g_preload_cv soit satisfaite. 
        // Pendant cette attente, elle libère le verrou associé au mutex g_preload_mutex, permettant à d'autres threads de le prendre.
        std::unique_lock <std::mutex> lck(g_preload_mutex);
        g_preload_cv.wait(lck); //wait for the preload signal

        if(g_is_exit == true) return; // sort de la boucle infinie si exit vrai
        if (g_is_path_changed == true) { //recharge l'archive avec la fonction loadArchive de l'objet image_processor et réinitialisation de la variable g_is_path_changed
            image_processor.loadArchive(g_archive_path);
            g_is_path_changed = false;
        }

        // Initialise plusieurs variables locales à partir des valeurs stockées dans la structure g_preload_params
        g_is_preload_run = true;

        bool left_exceed = false;
        bool right_exceed = false;
        int page_type = g_preload_params.page_type;
        int page_num_current = g_preload_params.page_num_current;
        int page_preload_left_size = g_preload_params.page_preload_left_size;
        int page_preload_right_size = g_preload_params.page_preload_right_size;

        //Une boucle qui itère à travers les pages à charger, en fonction des paramètres page_preload_left_size et page_preload_right_size
        for (int i = 1; i <= qMax<int>(page_preload_left_size, page_preload_right_size); i++) {

            //Charge les pages à droite et à gauche de la page courante, en utilisant la fonction loadAndCacheImage
            if (page_num_current + i <= g_page_num_total && i <= page_preload_right_size) {
                loadAndCacheImage(page_num_current + i, page_type);
            }
            else right_exceed = true;

            if (page_num_current - i >= 1 && i <= page_preload_left_size) {
                loadAndCacheImage(page_num_current - i, page_type);
            }
            else left_exceed = true;

            //Si les limites droite et gauche sont atteintes ou si g_is_page_current_changed ou g_is_path_changed est vrai, la boucle est interrompue, et la fonction peut être appelée à nouveau avec de nouveaux paramètres
            if (left_exceed == true && right_exceed == true) break;
            if (g_is_page_current_changed == true || g_is_path_changed == true) {
                //need to rerun this function from new params
                if(g_is_page_current_changed == true) g_is_page_current_changed = false;
                break;

            }
        }
        g_is_preload_run = false;
    }
    return;


}
