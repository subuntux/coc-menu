#include <stdio.h>
#include <stdlib.h>

void setupNode();
void setupNvim();
void installCocSettings();
void installVimPlug();
void selectOption();

int main() {
    while (1) {
        selectOption();
        printf("\n");
    }
    return 0;
}

void selectOption() {
    int option1;
    printf("Welcome by COC-NVIM Setup Menu\n");
    printf("[1] Setup nodejs/npm\n");
    printf("[2] Setup nvim\n");
    printf("[3] Install coc-settings\n");
    printf("[4] Install vim-plug (after [3])\n");
    printf("[0] Exit\n");

    printf("select: ");
    scanf("%d", &option1);

    switch (option1) {
        case 1:
            setupNode();
            break;
        case 2:
            setupNvim();
            break;
        case 3:
            installCocSettings();
            break;
        case 4:
            installVimPlug();
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Option\n");
    }
}

void setupNode() {
    int option2;
    printf("Which Distro\n");
    printf("[1] Ubuntu/Debian\n");
    printf("[2] Termux\n");
    printf("[0] Exit\n");

    printf("select: ");
    scanf("%d", &option2);

    switch (option2) {
        case 1:
            printf("[+] Start Setup (Ubuntu/Debian)\n\n");
            system("sudo apt install nodejs npm git -y");
            break;
        case 2:
            printf("[+] Start Setup (Termux)\n\n");
            system("pkg install termux-api -y");
            system("termux-notification --title \"Installing nodejs/npm\" --content \"Termux install actually nodejs and npm\" --priority high");
            system("pkg install nodejs -y");
            system("termux-notification --title \"Installing Successful\" --content \"The Installing was Successful. Start Install git\" --priority high");
            system("pkg install git -y");
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Option\n");
    }
}

void setupNvim() {
    int option3;
    printf("Which Distro\n");
    printf("[1] Ubuntu/Debian\n");
    printf("[2] Termux\n");
    printf("[0] Exit\n");

    printf("select: ");
    scanf("%d", &option3);

    switch (option3) {
        case 1:
            printf("[+] Install nvim (Ubuntu/Debian)\n\n");
            system("sudo apt install neovim -y");
            break;
        case 2:
            printf("[+] Install nvim (Termux)\n\n");
            system("termux-notification --title \"Installing Neovim\" --content \"Termux install neovim\" --priority high");
            system("pkg install neovim -y");
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid Option\n");
    }
}

void installCocSettings() {
    printf("[+] Installing coc-settings\n\n");
    system("cd $HOME");
    system("mkdir .config");
    system("wget https://raw.githubusercontent.com/subuntux/coc-menu/main/settings/coc-nvim.tar.xz");
    system("tar -xJf coc-nvim.tar.xz");
    system("rm coc-nvim.tar.xz");
    system("mv nvim .config/");
}

void installVimPlug() {
    printf("[+] Installing vim-plug\n\n");
    system("curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim");
}
