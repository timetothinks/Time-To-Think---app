#!/bin/bash

for file in *.png; do
    convert "$file" \
        -alpha on \
        -channel RGB \
        -fill white \
        -colorize 100 \
        +channel \
        "$file"

    echo "Convertido: $file"
done

echo "Conversión finalizada."