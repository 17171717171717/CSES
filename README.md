1.git clone https://github.com/17171717171717/CSES.git
2.cd CSES
3.丟新 folder 進去
4.git add new_folder
5.git commit -m "Add new_folder with README.md"
6.git push origin main


git clean -nd => git clean -fd
別亂刪除東西

# 把變更加進來（例如你改了很多檔案）
git add .

# 提交 commit（寫一個訊息）
git commit -m "更新了本地內容，例如 XXX 題解"

# 推送到 GitHub
git push origin main
