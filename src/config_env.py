######################################################################
### author = Rafael Zamora 
### copyright = Copyright 2020-2022, Next Project 
### date = 07/01/2022
### license = PSF
### version = 3.0.0 
### maintainer = Rafael Zamora 
### email = rafa.zamora.ram@gmail.com 
### status = Production
######################################################################

#System Packages
import os

#Check if it exists NEXT_PACKAGES_DIR
def check_env():
    try:
        #Search NEXT_PACKAGES_DIR
        next_dir = os.environ['NEXT_PACKAGES_DIR']
        print("NEXT_PACKAGES_DIR in:", next_dir)
    except:
        #Not Find NEXT_PACKAGES_DIR
        print("It was not found ENV NEXT_PACKAGES_DIR")

        #Want to create NEXT_PACKAGES_DIR
        print("Create NEXT_PACKAGES_DIR y/n: ", end="")
        create_next_packages_dir_flag = input()

        #Create or Not NEXT_PACKAGES_DIR
        if create_next_packages_dir_flag == "y":

            #Select dir for NEXT_PACKAGES_DIR
            select_next_packages_dir()
        else:

            #Warning is not created NEXT_PACKAGES_DIR
            print("Warning!!! you must create NEXT_PACKAGES_DIR")
        exit()

#Select dir for NEXT_PACKAGES_DIR
def select_next_packages_dir():

    #Search home dir
    home_dir = os.environ['HOME']

    #Default dor for NEXT_PACKAGES_DIR
    next_packages_dir = home_dir + "/NextPackages"

    #Acept dir for NEXT_PACKAGES_DIR
    print("NEXT_PACKAGES_DIR will be created in: " + home_dir + " y/n:", end="")
    next_packages_dir_flag = input()

    #Use default dor for NEXT_PACKAGES_DIR or not
    if next_packages_dir_flag == "y":

        #Create dir for NEXT_PACKAGES_DIR
        create_next_packages_dir(next_packages_dir)
    else:
        #Select dir for NEXT_PACKAGES_DIR
        print("Enter the route where you want NEXT_PACKAGES_DIR: ", end="")
        next_packages_dir = input()

        #Create dir for NEXT_PACKAGES_DIR
        create_next_packages_dir(next_packages_dir + "/NextPackages")

#Create dir for NEXT_PACKAGES_DIR
def create_next_packages_dir(dir):

    #verify that it does not exist dir for NEXT_PACKAGES_DIR
    if not os.path.isdir(dir):
        #Create dir for NEXT_PACKAGES_DIR
        os.mkdir(dir)

    print('Now add environment variable NEXT_PACKAGES_DIR='+ dir)
