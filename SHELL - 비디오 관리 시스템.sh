#!/bin/bash

while :
do
    echo "Please Select: "
    echo "    1. Create Account"
    echo "    2. Query Account"
    echo "    3. Rent Video"
    echo "    4. Return Video"
    echo "    0. Quit"
    read menu_number
        case $menu_number in
        1)
            echo
            echo "[1] Create Account"
            echo "Enter Customer Info:"
            read -p "Name: " Name
            touch "$Name.txt"
            read -p "Phone Number: " Phone_Number
            touch Phone_Number.txt
            echo "$Name-$Phone_Number" >> Phone_Number.txt
            echo
            echo "Press Enter"
            read enter
            ;;
        2)
            echo
            echo "[2] Query Account"
            read -p "Enter Name: " Name
            echo "Video Rented"
            divider===============
            divider=$divider$divider$divider
            echo "$divider"
            a=0
            readarray my_array < "$Name.txt"
            for line in "${my_array[@]}";
            do
                ((a++))
                echo "$a. $line"
            done
            echo "$divider"
            echo
            echo "Press Enter"
            read enter
            ;;
        3)
            echo
            echo "[3] Rent Video"
            read -p "Enter Name: " Name
            echo "Videos Available"
            divider===============
            divider=$divider$divider$divider
            echo "$divider"
            a=0
            readarray my_array < Video_profile.txt
            for line in "${my_array[@]}";
            do
                ((a++))
                echo "$a. $line"
            done
            echo "$divider"
            read -p "Please Select Number: " Rent_Number
            echo "$(sed -n ''$Rent_Number'p' Video_profile.txt) is rented now."
            echo "$(sed -n ''$Rent_Number'p' Video_profile.txt)   $(date +%m/%d)" >> "$Name.txt"
            echo
            echo "Press Enter"
            read enter
            ;;

        4)
             echo
             echo "[4] Return Video"
             read -p "Enter Name: " Name
             echo "Videos Rented"
             divider===============
             divider=$divider$divider$divider
             echo "$divider"
             a=0
             readarray my_array < "$Name.txt"
             for line in "${my_array[@]}";
             do
                ((a++))
                echo "$a. $line"
             done
             echo "$divider"
             read -p "Please Select Number: " Return_Number
             echo "$(sed -n ''$Return_Number'p' "$Name.txt") is returned"
             echo "$(sed -i ''$Return_Number'd' "$Name.txt")" >> "$Name.txt"
             echo
             echo "Press Enter"
             read enter
             ;;
       0)
            break;
            ;;
       *)
            echo "wrong command"
            ;;
        esac
done
