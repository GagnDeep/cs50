function formatAllData(data){
    let yearData = {}
    data.forEach(arr => {
        if(!yearData[arr.year]) yearData[arr.year] = [];
        let yearArr = yearData[arr.year];
        let region = yearArr.find(d=>d.country == arr.country);
        if(!region) yearArr.push(arr)
    })
    return yearData;
}

function formatter(row){
        return {
            country : row.Country,
            continent : row.Continent,
            countryCode : +row['Country Code'],
            emissions : +row['Emissions'],
            emissionsPerCapita : +row['Emissions Per Capita'],
            region : row.Region,
            year : +row.Year
        }
}

function countryFormatter(data){
    let cData = {};
    data.forEach(obj=>{
    	let c = obj.countryCode
    	if(!cData[c]) cData[c] = [];
    	let cArr = cData[c];
    	let region = cArr.find(d=>d.year == obj.year) ;if(!region) cArr.push(obj)
    })
    let arr = [], minmax = d3.extent(Object.keys(yearData));
    for(var i = minmax[0]; i<=minmax[1]; i++){
        arr.push({emissionsPerCapita : 0, emissions : 0 , year : +i})
    }
    // debugger;
    cData[-1] = arr
    return cData;
}
function eventListeners(minMax){

        d3.select('select')
                .on('change', ()=>{
                    dataType = d3.event.target.value;
                    makeMap(+d3.select('input').property('value'))
                    histogram({id:id})
                })

        d3.select('input')
                .attr('min', minMax[0])
                .attr('max', minMax[1])
                .attr('value', minMax[0])
                .on('input', ()=>makeMap(+d3.event.target.value));



}

function showTooltip(d){
    year = d3.select('input').property('value')
    let data = countryData[+d.id].find(d=>d.year == year)
    let tooltip = d3.select('.tooltip');

    tooltip
        .style('opacity', 1)
        .style('left', d3.event.x - (tooltip.node().offsetWidth/2) +'px')
        .style('top', d3.event.y+25+'px')
        .html(`
            <p>country: ${data.country}</p>
            <p>${dataType}: ${data[dataType]}</p>
            <p>year: ${data.year}</p>
        `)
}