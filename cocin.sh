#!/bin/bash

select_option() {
    echo "Welcome by COC-NVIM Setup Menu"
    echo "[1] Setup nodejs/npm"
    echo "[2] Setup nvim"
    echo "[3] Install coc-settings"
    echo "[4] Install vim-plug (after [3])"
    echo "[0] Exit"
    
    read -p "select: " option1
    
    case $option1 in
        1)
            setup_node
            ;;
        2)
            setup_nvim
            ;;
        3)
            cd $HOME
            mkdir .config
            wget https://raw.githubusercontent.com/subuntux/coc-menu/main/settings/coc-nvim.tar.xz
            tar -xJf coc-nvim.tar.xz
            rm coc-nvim.tar.xz
            mv nvim .config/
            ;;
        0)
            exit 0
            ;;
        4)
            curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
            ;;
        *)
            echo "Invalid Option"
            ;;
    esac
}

setup_node() {
    echo "Which Distro"
    echo "[1] Ubuntu/Debian"
    echo "[2] Termux"
    echo "[0] Exit"
    
    read -p "select: " option2
    
    case $option2 in
        1)
            echo "[+] Start Setup (Ubuntu/Debian)"
            echo " "
            sudo apt install nodejs -y
            sudo apt install npm -y
            sudo apt install git -y
            ;;
        2)
            echo "[+] Start Setup (Termux)"
            echo " "
            pkg install nodejs -y
            pkg install git -y
            ;;
        0)
            exit 0
            ;;
        *)
            echo "Invalid Option"
            ;;
    esac
}

setup_nvim() {
    echo "Which Distro"
    echo "[1] Ubuntu/Debian"
    echo "[2] Termux"
    echo "[0] Exit"
    
    read -p "select: " option3
    
    case $option3 in
        1)
            echo "[+] Install nvim (Ubuntu/Debian)"
            echo " "
            sudo apt install neovim -y
            ;;
        2)
            echo "[+] Install nvim (Termux)"
            echo " "
            pkg install neovim -y
            ;;
        0)
            exit 0
            ;;
        *)
            echo "Invalid Option"
            ;;
    esac
}

main() {
    while true; do
        select_option
        echo ""
    done
}

main
