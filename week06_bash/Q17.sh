#!/bin/bash

file_wordcnt() {
    files=$(ls *.txt)                # 현재 디렉토리의 .txt 파일 목록을 문자열로 저장
    for file in $files; do           # 목록을 순회
        count=$(cat $file | wc -w)  # cat으로 내용 출력 → wc -w로 단어 수 세기
        echo "$file 파일의 단어는 $count개 입니다."
    done
}

file_wordcnt

