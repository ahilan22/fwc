## initial setup (in github website)
### generating personal access token:
1. from Settings-->Developer settings-->Generate new token
2. give all access - tick all those boxes
1. save it in a .txt file for future use

## cloning your repo  
1. create a new repo using github website or go to your existing repo and copy the repo's https link from **Code** button; _(use Desktop Site if you are using browser on mobile)_
1. go to your local directory where you need to place your repo (we'll clone your repo there from site)
    * **in termux**: clone into to root directory (not working in sdcard directory "for me")
1. open that directory in terminal and `git clone https://github.com/gadepall/fwc-1.git `

## uploading your repo - **Basic Workflow**
1. after adding and editing files; to upload into your github repo:
    ```bash
    git add circles/
    git commit -m "mandatory message"
    git push
    ```
1. usually command line prompts for git username, then it asks for password-->enter the personal access token here
