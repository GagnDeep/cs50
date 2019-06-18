function makeMap(year){
            let data            = yearData[year],
                domains         = {
                                    emissions: [0, 2.5e5, 1e6, 5e6],
                                    emissionsPerCapita: [0, 0.5, 2, 10]
                                  },
                colorScale      = d3.scaleLinear()
                                     .domain(domains[dataType])
                                     .range(["#f1c40f", "#e67e22", "#e74c3c", "#c0392b"]);

            makePie(data);
            updateColor();

            countries
                .attr('fill', colordata=>{
                    let id = data.find(d=>+d.countryCode == +colordata.id);
                    if(id) return colorScale(id[dataType]); else return '#ccc';
                });
        }

