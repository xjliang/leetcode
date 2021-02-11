#!/bin/bash

pushd `dirname $0` > /dev/null
SCRIPTPATH=`pwd -P`
popd > /dev/null
SCRIPTFILE=`basename $0`

COLOR_INFO='\033[0;36m'
COLOR_NONE='\033[0m'

source ${SCRIPTPATH}/lib/query_problem.sh

function usage()
{

    echo -e "Usage: ${0} [file]"
    echo -e ""
    echo -e "Example:"
    echo -e ""
    echo -e "   ${0} ./LargestNumber.cpp"
    echo -e ""
}



if [ $# -lt 1 ] || [[ ! -f ${1} ]]; then
    usage
    exit 255
fi

DIR=`cd $(dirname ${1}) && pwd -P`
FILE=${DIR}/$(basename ${1})

URL=`grep Source ${FILE} | awk '{print $4}'`

URL=$(echo $URL | sed -e 's/oj\.leetcode\.com/leetcode\.com/g')

get_question_slug ${URL}
query_problem ${URL} ${QUESTION_TITLE_SLUG}

#echo "$QUESTION_CONTENT"
#echo $QUESTION_DIFFICULTY
#echo $QUESTION_TITLE
#echo $QUESTION_ID
#echo $QUESTION_FRONTEND_ID
#echo $QUESTION_CATEGORY
#echo $QUESTION_TOPTAGS

### 方法简要说明：
### 1. 是先查找一个字符串：带双引号的key。如果没找到，则直接返回defaultValue。
### 2. 查找最近的冒号，找到后认为值的部分开始了，直到在层数上等于0时找到这3个字符：,}]。
### 3. 如果有多个同名key，则依次全部打印（不论层级，只按出现顺序）
###
### 3 params: json, key, defaultValue
function getJsonValuesByAwk() {
    awk -v json="$1" -v key="$2" -v defaultValue="$3" 'BEGIN{
        foundKeyCount = 0
        while (length(json) > 0) {
            # pos = index(json, "\""key"\""); ## 这行更快一些，但是如果有value是字符串，且刚好与要查找的key相同，会被误认为是key而导致值获取错误
            pos = match(json, "\""key"\"[ \\t]*?:[ \\t]*");
            if (pos == 0) {if (foundKeyCount == 0) {print defaultValue;} exit 0;}

            ++foundKeyCount;
            start = 0; stop = 0; layer = 0;
            for (i = pos + length(key) + 1; i <= length(json); ++i) {
                lastChar = substr(json, i - 1, 1)
                currChar = substr(json, i, 1)

                if (start <= 0) {
                    if (lastChar == ":") {
                        start = currChar == " " ? i + 1: i;
                        if (currChar == "{" || currChar == "[") {
                            layer = 1;
                        }
                    }
                } else {
                    if (currChar == "{" || currChar == "[") {
                        ++layer;
                    }
                    if (currChar == "}" || currChar == "]") {
                        --layer;
                    }
                    if ((currChar == "," || currChar == "}" || currChar == "]") && layer <= 0) {
                        stop = currChar == "," ? i : i + 1 + layer;
                        break;
                    }
                }
            }

            if (start <= 0 || stop <= 0 || start > length(json) || stop > length(json) || start >= stop) {
                if (foundKeyCount == 0) {
					print defaultValue;
				}
				exit 0;
            } else {
				if (foundKeyCount > 1) {
					printf ", "
				}
                printf substr(json, start + 1, stop - start - 2);
            }

            json = substr(json, stop + 1, length(json) - stop)
        }
    }'
}

QUESTION_TAG=$(getJsonValuesByAwk "$QUESTION_TOPTAGS" "name" "defaultValue")

FILE=`echo ${FILE} | sed "s/.*\/algorithms/\.\/algorithms/"`

echo "|${QUESTION_FRONTEND_ID}|[${QUESTION_TITLE}](${URL}) | [C++](${FILE})|${QUESTION_DIFFICULTY}|${QUESTION_TAG}|"
