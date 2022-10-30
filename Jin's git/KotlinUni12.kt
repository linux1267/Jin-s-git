//숫자를 입력받고 그 입력받은 숫자를 인덱스로 사용하여 정수형 배열에 있는 수를 뽑아낸다.
//만약 입력받은 숫자가 인덱스 범위를 넘어간다면 null을 반환한다.

fun readInt() = try {
    readLine()?.toInt()
} catch (e: NumberFormatException) {
    null
}

fun main() {
    val arr = intArrayOf(3, 9, 7, 6, 4)
    val num = readInt()


    val result = num?.let { arr.getOrNull(it) } //num이 null이 아닌경우
    //val result = if( num != null ) arr.getOrNull(num) else null

    if( result != null ){
        println(result)
    }
}