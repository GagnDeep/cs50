function histogram(data){
// debugger
        id = +data.id
    let country             = countryData[+data.id].sort((a,b)=>a.year-b.year),
        height              = 300,
        width               = 615,
        barPadding          = 1,
        padding             = 50,
       xScale               = d3.scaleLinear()
                                    .domain(d3.extent(country, d=>d.year))
                                    .range([padding, width - padding]),

       yScale               = d3.scaleLinear()
                                    .domain([0,d3.max(    country, d=>d[dataType])])
                                    .range([height-padding, padding]),

       svg                  = d3.select('#histogram')
                                  .attr('height', height)
                                  .attr('width', width),

       barWidth             = xScale(xScale.domain()[0]+1) - xScale.range()[0],

       update               = svg
                                .selectAll('.bar')
                                .data(country),

      t                     = d3.transition()
                                  .duration(900)
                                  .ease(d3.easeBounceOut);

debugger;
        d3.select('.x-axis')
        .attr('transform', `translate(0, ${height - padding})`)
            .call(d3.axisBottom(xScale)
                .tickFormat(d3.format(".0f")))

        d3.select('.y-axis')
            .attr('transform', `translate(${padding-barWidth/2}, 0)`)
            .transition()
            .duration(1000)
            .call(d3.axisLeft(yScale))


        update
            .exit()
            .transition(t)
            .delay((d,i,nodes)=>(nodes.length-i-1)*10)
            .attr('y', height-padding)
            .attr('height', 0)
            .remove();

        update
            .enter()
            .append('rect')
            .classed('bar', true)
            .attr('y', height-padding)
            .attr('height', 0)
            .merge(update)
            .attr('x', d=>(xScale(d.year)+xScale(d.year-1))/2)
            .attr('width', barWidth-barPadding)
            .transition(t)
            .delay((d,i)=>i*30)
            .attr('y', d=>yScale(d[dataType]))
            .attr('height',d=> height-padding-yScale(d[dataType]) )
updateColor()

}

function updateColor(){

    let year = d3.select('input')
                                  .property('value');
    d3.selectAll('.bar')
        .attr('fill', d=>d.year == year ? "#16a085" : "#1abc9c")
}

