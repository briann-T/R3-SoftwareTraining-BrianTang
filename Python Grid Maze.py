import pygame
import random
from pygame.locals import*
WIDTH = 800
HEIGHT = 800
FPS = 30

pygame.init()
pygame.mixer.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Grid")
clock = pygame.time.Clock()
white = [255, 255, 255]
black = [0,0,0]
red = [255,0,0]
screen.fill(white)

n=int(input("Enter the grid value "))
width=800/n
height=800/n
def drawGrid():
    for x in range(1,n):
        pygame.draw.line(screen,black,((width)*x,0),((width)*x,HEIGHT),1)
        pygame.draw.line(screen,black,(0,(height)*x),(WIDTH,(height)*x),1)
        pygame.display.update()

def down(x,y):
    pygame.draw.rect(screen,white,(x*width+1,(height*y)-1,width-1,height+1))
    pygame.display.update()

def right(x,y):
    pygame.draw.rect(screen,white,(x*width,(height*y)+1,width,height-1))
    pygame.display.update()

def generateMaze():
    for x in range (n):
        right(x,0)
        down(0,x)
        for y in range (n):
            t=random.randint(1,2)
            if t==1:
                down(x,y)
            else:
                right(x,y)

drawGrid()
generateMaze()
pygame.draw.line(screen,black,(0,0),(WIDTH,0),1)
pygame.draw.line(screen,black,(0,0),(0,HEIGHT),1)
pygame.display.update()

