import os
import pygame
from pygame import mixer
from pygame.locals import *
import serial.tools.list_ports
import time
import random
import serial


found = False
BLACK = (0, 0, 0)
WHITE = (255,255,255)
X = 7000
Y = 900

#number of sound effects in folder
numOfSoundEffects = 4

pygame.init()

# find all ports and select arduino

while(found == False):
    ports = serial.tools.list_ports.comports(include_links=False)
    for port, desc, _ in sorted(ports):
            if(str(desc).__contains__("Arduino") or str(desc).__contains__("arduino")):
                _serial = serial.Serial(port=str(port), baudrate=9600)
                print("Found:", port)
                found = True

# initialise and play the music
mixer.init()
mixer.music.load(os.getcwd() + '\OneDrive\Documents\Laser\Sounds\MI_soundtrack.wav')
mixer.music.play(2)
screen = pygame.display.set_mode((X, Y))

#set the font for the text
sysfont = pygame.font.get_default_font()
#print('system font :', sysfont)

font = pygame.font.SysFont(None, 240)

count = 1
level = font.render(f"Level {str(count)}", True, WHITE)
level_text = level.get_rect(center=(screen.get_rect().centerx, screen.get_rect().centery - 200))
screen.blit(level, level_text)


img = font.render("Start", True, WHITE)
text_rect = img.get_rect(center=(screen.get_rect().center))
screen.blit(img, text_rect)

score = 0
running = True
background = BLACK

while running:
    score += 1
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
    
	#------reads from serial-----------
    while _serial.in_waiting:
        line = str(_serial.readline()).replace('b', "").replace('\\r', "").replace('\\n', "").replace('\'', "") 
        print(line)
        
        #plays when the user gets a point
        if not(line == 'Start'): 
            count+=1
            print(f'Level {count} complete')
            _sound = random.randint(1, numOfSoundEffects)
            try:
                mixer.Sound(os.getcwd() + f'\OneDrive\Documents\Laser\Sounds\{_sound}.mp3').play()
            except:
                continue
            #print(os.getcwd() + f'\OneDrive\Documents\Laser\{_sound}.wav')

        #Game over sound is played
        if(line == 'Game Over'):
             mixer.music.stop()
             mixer.Sound(os.getcwd() + f'\OneDrive\Documents\Laser\Sounds\game_over.mp3').play() 

        img = font.render(line, True, WHITE)
        level = font.render(f'Level {str(count)}', True, WHITE)
        text_rect = img.get_rect(center=(screen.get_rect().center))
        level_text = level.get_rect(center=(screen.get_rect().centerx , screen.get_rect().centery - 250))
        screen.fill(background)
        screen.blit(img, text_rect)
        screen.blit(level, level_text)
        pygame.display.update()
    
pygame.quit()