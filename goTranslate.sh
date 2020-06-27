#!/bin/bash

str_old=$(cat ~/Translator/lastContent)
str_new=$(xclip -o 2>/dev/null | xargs)
if [[ "$str_new" != "$str_old" && $str_new ]]; then
	echo -e "\n"
	count=$(echo "$str_new" | wc -w)
	if [ "$count" == "1" ]; then
        	echo -n -e "$str_new " >> ~/Translator/words
		echo "$str_new" | trans :zh-CN | tail -1 | cut -c 5- | sed "s,\x1b\[[0-9;]*[a-zA-Z],,g" | tee -a ~/Translator/words
	else
		echo "$str_new" | trans :zh-CN -b
	fi
    	echo "$str_new" > ~/Translator/lastContent
fi
