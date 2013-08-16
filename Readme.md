### THIS APP IS NO LONGER MAINTAINED

Bug reports, feature and pull requests will no longer be entertained.

This is a simple program I wrote using C because I was too lazy to see individual folders to take my backup. Most backup program allow you to sync your hard disk with external rewritable drive, such as pen drives, external hard drive or a upload server. This one will help you to sync your drive (or a part of it) with non-rewriteable media such as DVDs which are cheapest for taking backups.

Using this program, you can:

* Check what files you need to add in your backup drive
* Check what files have been modified since the last backup
* Know if two directory structure are synced or not.
* Check what files have been deleted since the last backup


The program works with the help of two input files, an old filelist text file and a new file list text file. This would work in Linux systems (I have tested it individually), sorry I dont know about windows as i dont have that installed.  8) 

Copy and save the program as BackupHelper.c, compile the program using gcc using the following code

```bash
$ gcc -Wall BackupHelper.c -o BackupHelper
```

Now, first take a backup of your hard disk (or a folder in it, say music) in a DVD. Now cd to that folder and create a filelist of that folder and save it in any name (say a.txt)

```bash
$ cd music
$ tree -fis > a.txt
```

Copy this file in the folder the program executable is present.
Note: If you dont use the -s option, the program wont check for file modifications or changes, it will only check for content added.

Now after some days (maybe when you have added more content in your music folder) cd to the folder you want to take the backup. Again create a filelist of that folder using the following commands.

```bash
$ cd music
$ tree -fis > b.txt
```

Copy the b.txt to the program's executable folder. Now you need to compare the both the files to see the changes in music folder. For that, type ./BackupHelper oldfilelist.txt newfilelist.txt and press enter.

```bash
$ ./BackupHelper a.txt b.txt
```

The program would display all the files and folders that have been added after your last backup. Now you can burn the changed or added files in your backup dvd.

![Output 1](http://img10.imageshack.us/i/screenshot3id.png)
![Output 2](http://img10.imageshack.us/img10/2867/screenshot3id.png)

Delete the old filelist file. Keep the new. Next time you want to take backup, cd to the folder and create the filelist file using tree -fis >filelist.txt command. Compare the older file with new one and you are done.

Please note: This program doesnt takes your backups, but rather helps you to, so the name is BackupHelper. For encryption or more advanced options, you can use deja dup. However you have to write another DVD everytime you backup, thus increasing file-redundancy and costs. This will help you keeping the directories synced, the backup, however, you have to do manually.

If no changes have been made since the last backup, the program would display a message saying so. It also displays the files that were present earlier but have been recently deleted. You can also use it to know if two folders are synced.
