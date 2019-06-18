
var colors = generateRandomColors(6);
    var pickedColor = pickColor();
    var colorDisplay = document.getElementById("colorDisplay");
    var messageDisplay = document.getElementById("message");
    var resetButton = document.querySelector("#reset");
    var easyBtn = document.getElementById("easyBtn");
    var hardBtn = document.getElementById("hardBtn");
    var h1 = document.querySelector("h1");
    var authStrip = document.getElementById("navBar");
    var numberOfSquares = 6;

    colorDisplay.textContent = pickedColor;


    easyBtn.addEventListener("click",function(){
        numberOfSquares = 3;
        hardBtn.classList.remove("selected");
        easyBtn.classList.add("selected");
        colors = generateRandomColors(numberOfSquares);
        pickedColor = pickColor();
        colorDisplay.textContent = pickedColor;
        for(var i =0;i<squares.length;i++){
            if(colors[i]){
                squares[i].style.background = colors[i];
            }else{
                squares[i].style.display = "none";
            }
        }
      h1.style.background = "steelblue";
      authStrip.style.background = "steelblue";
    });


    hardBtn.addEventListener("click",function(){
        numberOfSquares = 6;
        hardBtn.classList.add("selected");
        easyBtn.classList.remove("selected");
        colors = generateRandomColors(numberOfSquares);
        pickedColor = pickColor();
        colorDisplay.textContent = pickedColor;
        for(var i =0;i<squares.length;i++){
            squares[i].style.background = colors[i];
            squares[i].style.display = "block";
        }
        h1.style.background = "steelblue";
        authStrip.style.background = "steelblue";
    })

    var squares = document.querySelectorAll(".square");
    resetButton.addEventListener("click",function(){
        colors=generateRandomColors(numberOfSquares);
        pickedColor = pickColor();
        colorDisplay.textContent = pickedColor;
        messageDisplay.textContent = "";
        this.textContent = "New Colors"
        for(i=0;i<squares.length;i++){
        //add inittial
        squares[i].style.background = colors[i];
        }
        h1.style.background = "steelblue";
        authStrip.style.background = "steelblue";

    })
    for(i=0;i<squares.length;i++){
        //add inittial
        squares[i].style.background = colors[i];

        squares[i].addEventListener("click",function(){
            var clickedColor = this.style.background;
            if(pickedColor === clickedColor){
                messageDisplay.textContent = "Correct";
                changeColours(clickedColor);
                resetButton.textContent = "Play again?";
                h1.style.background = clickedColor;
                authStrip.style.background = clickedColor;
            }else{
                this.style.background = "#232323";
                messageDisplay.textContent = "Try Again";
            }
        })
    }

    function changeColours(color){
        for(var i =0;i<squares.length;i++){
            squares[i].style.background = color;
        }
    }
    function pickColor(){
      return colors[Math.floor(Math.random()*colors.length)];
    }
    function generateRandomColors(num){
        var arr = [];
        for(var i =0;i<num;i++){
            arr.push(randomColor());
        }
        return arr;
    }
    function randomColor(){
        var red = Math.floor(Math.random()*256);
        var green = Math.floor(Math.random()*256);
        var blue = Math.floor(Math.random()*256);
        str = "rgb(" + red+", " +green+", "+blue+")";
        return str;
    }





// var minYear = d3.min(birthData, function(d) {
//   return d.year;
// });
// var maxYear = d3.max(birthData, function(d) {
//   return d.year;
// });
// var width = 600;
// var height = 600;
// var barPadding = 10;
// var numBars = 12;
// var barWidth = width / numBars - barPadding;
// var maxBirths = d3.max(birthData, function(d) {
//   return d.births;
// });
// var yScale = d3.scaleLinear()
//               .domain([0, maxBirths])
//               .range([height, 0]);

// d3.select("input")
//     .property("min", minYear)
//     .property("max", maxYear)
//     .property("value", minYear);

// d3.select("svg")
//     .attr("width", width)
//     .attr("height", height)
//   .selectAll("rect")
//   .data(birthData.filter(function(d) {
//     return d.year === minYear;
//   }))
//   .enter()
//   .append("rect")
//     .attr("width", barWidth)
//     .attr("height", function(d) {
//       return height - yScale(d.births);
//     })
//     .attr("y", function(d) {
//       return yScale(d.births);
//     })
//     .attr("x", function(d,i) {
//       return (barWidth + barPadding) * i;
//     })
//     .attr("fill", "purple");

// d3.select('svg')
//     .append('text')
//     .classed('text', true)
//     .attr('x', width/2)
//     .attr('y', 30)
//     .text('birthData in '+minYear)
//     .style('text-anchor', 'middle')
//     .style('font-size', '2em')

// d3.select("input")
//     .on("input", function() {
//       var year = +d3.event.target.value;
//       d3.selectAll("rect")
//         .data(birthData.filter(function(d) {
//           return d.year === year;
//         }))
//           .transition()
//           .delay((d,i)=>i*250)
//           .duration(4000)
//           .on('start', (s,i)=>{
//             if(i === 0){d3.select('.text')
//             .text('updating to year ' + year +' data...')}
//           })
//           .on('end', (s,i,nodes)=>{
//             if(i === nodes.length-1){d3.select('.text')
//               .text('birthData in '+ year)}
//           })
//           .attr("height", function(d) {
//             return height - yScale(d.births);
//           })
//           .attr("y", function(d) {
//             return yScale(d.births);
//           });
//     });