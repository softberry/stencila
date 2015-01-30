#include <algorithm>

#include <boost/regex.hpp>

#include <stencila/stencil.hpp>
#include <stencila/string.hpp>

namespace Stencila {

std::string Stencil::title(void) const {
    return select("#title").text();
}

std::string Stencil::description(void) const {
    return select("#description").text();
}

std::vector<std::string> Stencil::keywords(void) const {
    std::vector<std::string> keywords;
    if(Node elem = select("#keywords")){
        auto text = elem.text();
        keywords = split(text,",");
        for(auto& keyword : keywords) trim(keyword);
    }
    return keywords;
}

std::vector<std::string> Stencil::authors(void) const {
    std::vector<std::string> authors;
    for(auto& author : filter(".author")){
        authors.push_back(author.text());
    }
    return authors;
}

std::vector<std::string> Stencil::contexts(void) const {
    std::vector<std::string> contexts;
    if(Node elem = select("#contexts")){
        // A #contexts node found so use that
        auto text = elem.text();
        contexts = split(text,",");
        for(auto& context : contexts) trim(context);
    } else {
        // Count the number of code directives of each type
        std::map<std::string,int> counts;
        auto codes = filter("[data-code]");
        for(auto code : codes){
            auto context = code.attr("data-code");
            if(counts.find(context)==counts.end()) counts[context] = 1;
            else counts[context] += 1;
        }
        // Sort in decending order of count
        std::vector<std::pair<std::string,int>> sorted;
        for(auto pair : counts) sorted.push_back(pair);
        auto cmp = [](std::pair<std::string,int> const & a, std::pair<std::string,int> const & b){ 
            return a.second > b.second;
        };
        std::sort(sorted.begin(), sorted.end(), cmp);
        for(auto pair : sorted) contexts.push_back(pair.first);

    }   
    return contexts;
}

std::string Stencil::theme(void) const {
    if(Node theme = select("#theme")) return theme.text();
    else return "core/stencils/themes/default";
}

Stencil::Parameter::Parameter(Node node){
    attribute = node.attr("data-par");
    boost::smatch match;
    static const boost::regex pattern("^([^:=]+)(:([a-z_]+))?(=(.+))?$");
    if(boost::regex_search(attribute, match, pattern)) {
        ok = true;
        name = match[1].str();
        type = match[3].str();
        default_ = match[5].str();
    } else {
        ok = false;
    }
}

std::vector<Stencil::Parameter> Stencil::pars(void) const {
    std::vector<Stencil::Parameter> pars;
    for(auto elem : filter("[data-par]")){
        Parameter par(elem);
        pars.push_back(par);
    }
    return pars;
}

}