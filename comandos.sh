#!/bin/bash

curl -silence -o site.txt https://hojenomundomilitar.com.br/suecia-e-finlandia-em-caminhos-diferentes-para-adesao-a-otan/
egrep -o OTAN site.txt > linhas.txt
wc -l linhas.txt


