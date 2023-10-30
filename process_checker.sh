#!/bin/bash

PATH+=:/Users/jeongsik/opt/anaconda3/bin

cd ~/Development/24H1_QE_Coding

git config --global user.email "jeongsikpyo@gmail.com"
git config --global user.name "OfficialTable"

echo ""
echo "Pulling from git..."
git pull

echo ""
echo "Running process_checker.py..."
python process_checker.py

echo ""
echo "Pushing to git..."
timestamp=$(date +"%Y-%m-%d %T")
git add .
git commit -m "Auto commit process_checker at $timestamp"
git push

echo ""
echo "Finished!"
