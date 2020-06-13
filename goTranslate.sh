#!/bin/bash

str_old=$(cat ~/Translator/lastContent.txt)
str_new=$(xclip -o 2>/dev/null | xargs)
if [[ "$str_new" != "$str_old" && $str_new ]]; then
	echo -e "\n"
	echo "$str_new" | xargs | trans :zh-CN -b
fi
echo "$str_new" | xargs > ~/Translator/lastContent.txt
