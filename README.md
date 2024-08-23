# Primeiro Projeto
Primeiro projeto utilizado para testar a instalação da Toolchain e do SDK da Raspberry Pi Pico (W)

    ## Compilando no Windows 
    Para compilar o projeto no Windows, para ser executado na placa física, execute os seguintes comandos no diretório raiz do projeto
    
    ```console
    mkdir build
    cd build
    cmake ..
    ninja
    ```
    
    Para compilar o projeto no Windows, para ser executado no simulador, execute os seguintes comandos no diretório raiz do projeto
    
    ```console
    mkdir build
    cd build
    cmake .. -DSIMULADOR="Y"
    ninja
    ```

    ## Compilando em Sistemas Operacionais Baseados em Linux 
    Para compilar o projeto em Sistemas Operacionais Baseados em Linux, execute os seguintes comandos no diretório raiz do projeto
    
    ```console
    mkdir build
    cd build
    cmake ..
    make
    ```
    Para compilar o projeto em Sistemas Operacionais Baseados em Linux/Unix, para ser executado no simulador, execute os seguintes comandos no diretório raiz do projeto
    
    ```console
    mkdir build
    cd build
    cmake .. -DSIMULADOR="Y"
    make
    ```