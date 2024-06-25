#!/bin/bash

generate_unique_numbers() {
    shuf -i 1-1000 -n 500
}

echo_color() {
    local text="$1"
    local color_code="$2"
    echo -e "${color_code}${text}\e[0m"  # \e[0m resets color attributes
}

for i in {1..40}
do
    numbers=$(generate_unique_numbers)
    number_array=($numbers)

    result=$(./push_swap "${number_array[@]}" | wc -l)

    if [ "$result" -gt 5500 ]; then
        echo_color "Execution $i: $result lines" "\e[31m"
        echo_color "Numbers: ${number_array[*]}" "\e[31m"
    else
        echo_color "Execution $i: $result lines" "\e[32m"
    fi
done
