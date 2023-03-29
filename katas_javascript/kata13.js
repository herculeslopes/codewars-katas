/* [5 kyu] Extract the domain name from a URL

    Write a function that when given a URL as a string, parses out just the domain name and returns it as a string. For example:

    domainName("http://github.com/carbonfive/raygun") == "github" 
    domainName("http://www.zombie-bites.com") == "zombie-bites"
    domainName("https://www.cnet.com") == "cnet"
*/

function domainName(url) {
    url = url.replace(/(http(s)?:\/\/)?(w{3}\.)?/, '');
    let re = /.*?\./;
    return re.exec(url)[0].replace('.', '');
}

console.log(domainName("http://github.com/carbonfive/raygun"));
// /.*?\./