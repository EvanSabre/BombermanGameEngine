#!/usr/bin/bash

DEFAULT_COLOR="\e[0m"
GREEN="\e[32m"
RED="\e[31m"

print_green() {
    echo -e "${GREEN}${1}${DEFAULT_COLOR}"
}

print_red() {
    echo -e "${RED}${1}${DEFAULT_COLOR}"
}

invalide_include="#include <unistd.h>"
search_director="src"

check_include() {
    grep -r "${invalide_include}" "${search_director}" && (print_red "invalide include found") || (print_green "Include checked : OK")
}

main() {
    check_include
}

main