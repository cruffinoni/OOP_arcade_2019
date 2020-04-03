Libcaca installation:
```bash
sudo apt-get install -y libcaca-dev
```

SDL installation:
```bash
sudo apt-get install libsdl-dev;
sudo apt-get install libsdl2-ttf-dev;
```

Doxygen:
- Installation: http://www.doxygen.nl/manual/install.html
- Generating documentation:
```bash
doxygen DocFileDoxygen;
cd latex;
make;
```

PDF Latex (needed to generate a pdf document from documentation):
```bash
sudo apt-get install texlive-latex-base texlive-fonts-recommended texlive-fonts-extra texlive-latex-extra
```
+ https://miktex.org/download
