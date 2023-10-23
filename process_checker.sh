#!/bin/bash

cd ~/Development/24H1_QE_Coding

git pull

python ./process_checker.py

git add .

timestamp=$(date +"%Y-%m-%d %T")

git commit -m "Auto commit process_checker at $timestamp"

git push