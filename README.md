# downloadapod

Program that downloads the NASA APOD (Astronomy Picture of the Day) and can set it as your wallpaper

[Go to NASA's APOD website](https://apod.nasa.gov/apod/astropix.html)

## Install:
Dependencies:
* curl
* feh (image viewer)

```bash
git clone https://github.com/Zombant/DownloadAPOD.git
cd DownloadAPOD
sudo make install
```

## Uninstall:
```bash
cd DownloadAPOD
sudo make uninstall
```

## Usage:
```
-h or --help: help
YYMMDD: date in YYMMDD format
-nw or --no-wallpaper: don't set as wallpaper
-r or --random: random image
-d DIR or --directory DIR: save image in DIR
```

