package com.example.myfirstkotlinapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.myfirstkotlinapp.databinding.ActivityMainBinding
import kotlin.random.Random

class MainActivity : AppCompatActivity() {
    lateinit var binding: ActivityMainBinding

    val array = intArrayOf(0, 0, 0, 0, 0)

    fun updateArrayUi() {
        binding.txtResult.text = "0"
        var str: String = ""
        for( elem in array ) str += "$elem "
        binding.txtRandoms.text = str
    }

    fun aggregate(array: IntArray, initValue: Int, op: (Int, Int) -> Int): Int {
        var result = initValue

        for(elem in array) {
            result = op(result, elem)
        }
        return result
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.btnRandoms.setOnClickListener {
            array[0] = Random.nextInt(0,100)
            array[1] = Random.nextInt(0,100)
            array[2] = Random.nextInt(0,100)
            array[3] = Random.nextInt(0,100)
            array[4] = Random.nextInt(0,100)
            updateArrayUi()
        }
        binding.btnSum.setOnClickListener {
            val sum: Int = aggregate(array,0 ) {result, elem -> result + elem}
            binding.txtResult.text = sum.toString()
        }
        binding.btnProduct.setOnClickListener {
            val product: Int = aggregate(array,1, ) {result, elem -> result * elem}
            binding.txtResult.text = product.toString()
        }
        binding.btnMax.setOnClickListener {
            val max: Int = aggregate( array, Int.MIN_VALUE ) {result, elem -> if( result > elem ) result else elem}
            binding.txtResult.text = max.toString()
        }
    }
}


/* 수업에 배운대로 aggregate 고차 함수를 이용하여 sum, product, max를 구하는 방법을 이용하여 결과를 보이는
안드로이드 프로그램을 작성한다.
오른 쪽에 보이는 대로 화면을 적당히 분배하여
- 맨 위에는 5개짜리 무작위 값의 정수 배열 표시
- 새로운 무작위값을 생성하는 버튼 ( Generate Random Array )
- 결과값
- sum, product, max를 결과값에 표시하도록 하는 버튼을 그려서 작동하도록 한다.
 */

//뷰바딩 활성화