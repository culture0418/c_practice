
import threading
import time
#Text to ASCII ART GENERATOR link : https: // patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
wish='''
   __        __         _   __                                ______
  / /  ___ _/ /  ___   (_) / /__ _  _____   __ _____  __ __  / / / /
 / _ \/ _ `/ _ \/ -_) / / / / _ \ |/ / -_) / // / _ \/ // / /_/_/_/ 
/_.__/\_,_/_.__/\__/ /_/ /_/\___/___/\__/  \_, /\___/\_,_/ (_|_|_)  
                                          /___/                                                                                                                                                                                    
'''
def task1():
	for letter in wish:
		time.sleep(0.0001)
		print(letter, end='')

t1 = threading.Thread(target=task1, name='t1')

#starting threads
t1.start()
wish.py