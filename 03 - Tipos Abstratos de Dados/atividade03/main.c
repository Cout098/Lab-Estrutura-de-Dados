#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "video.h"

int main(){
    setlocale(LC_ALL,"Portuguese");
    
    tp_gerenciador gerenciador;
    
    inicializar(&gerenciador);
    menu(&gerenciador);
    return 0;
}