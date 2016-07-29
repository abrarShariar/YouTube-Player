# [YouTube-Player]()

A customizable "YouTube-Player" with some handy features. Built on Qt v.5.7, written in C++. [Download & Play]() 


## Preview

![preview](https://raw.githubusercontent.com/abrarShariar/YouTube-Player/master/youtube-player-01.png)


## How to build and run


If you have **Qt-Creator** on your machine, you can grab the [source code](https://github.com/abrarShariar/YouTube-Player/archive/master.zip) and open [YouTube-Player.pro](https://github.com/abrarShariar/YouTube-Player/blob/master/src/YouTube-Player.pro)


### Linux:
	
  
### Windows: 
    


## Features

 - [YouTube](www.youtube.com) home page is displayed initially
 - You can choose any video just like you do in any browser and play
 - You can either choose to play it once or in a loop
 - Choose from several available features from the toolbar
 
 ![toolbar](https://raw.githubusercontent.com/abrarShariar/YouTube-Player/master/youtube-player-toolbar.png)
 	
   - Create your own customized "Playlist" with the number of repeat times included 

![playlist_add](https://raw.githubusercontent.com/abrarShariar/YouTube-Player/master/youtube-player-02.png)
	
## How it Works

- The application heavily uses Qt's Web Engine
- [main.cpp](https://github.com/abrarShariar/YouTube-Player/blob/master/src/main.cpp) is the default entry point
- The web engine view is implemented in [webview.cpp](https://github.com/abrarShariar/YouTube-Player/blob/master/src/webview.cpp)
- [dialog.cpp](https://github.com/abrarShariar/YouTube-Player/blob/master/src/dialog.cpp) contains code which interacts with user when **Add to playlist** is clicked
- [playlist.cpp](https://github.com/abrarShariar/YouTube-Player/blob/master/src/playlist.cpp) implements the customizable **Playlist** (the GUI needs much improvement,its kept minimal for now)
	

