#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

echo "Creating virtual environment..."
python -m venv venv

echo "Activating virtual environment..."
source venv/bin/activate  # for Mac/Linux
# For Windows (PowerShell): venv\Scripts\activate

echo "Upgrading pip..."
pip install --upgrade pip

echo "Installing dependencies..."
pip install -r requirements.txt

echo "Setup complete. Activate the virtual environment with:"
echo "source venv/bin/activate   # Mac/Linux"
echo "venv\\Scripts\\activate    # Windows"
