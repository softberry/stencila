#include <stencila/component.hpp>

namespace Stencila {

std::string Component::path(bool ensure) const {
	if(meta_){
		if(meta_->path.length()==0 and ensure){
			// Remove constness so that the setter can be called
			const_cast<Component&>(*this).path(std::string(""));
		}
		return meta_->path;
	} else {
		if(ensure){
			const_cast<Component&>(*this).path(std::string(""));
			return meta_->path;
		}
		else return "";
	}
}

Component& Component::path(const std::string& path) {
	using namespace boost::filesystem;
	if(not meta_) meta_ = new Meta;
	std::string current_path = meta_->path;
	std::string new_path = path;
	// If the current path is empty...
	if(current_path.length()==0){
		// If the new path is empty then...
		if(new_path.length()==0){
			// Create a unique one
			boost::filesystem::path unique = stores()[1];
			unique /= unique_path("temp/%%%%-%%%%-%%%%-%%%%");
			create_directories(unique);
			meta_->path = unique.string();
		} else {
			// Create the path if necessary
			if(not exists(new_path)){
				create_directories(new_path);
			}
			meta_->path = canonical(absolute(new_path)).string();
		}
	} 
	// If the current path is not empty...
	else {
		/// and the new path is not empty...
		if(new_path.length()>0){
			// create necessary directories for the following rename operation
			create_directories(new_path);
			// move (i.e rename) existing path to the new path.
			rename(current_path,new_path);
			meta_->path = canonical(absolute(new_path)).string();
		}
	}
	return *this;
}

Component& Component::path(const char* path) {
	return Component::path(std::string(path));
}

std::string Component::address(bool ensure) {
	std::string path = this->path(ensure);
	if(path.length()>0){
		for(auto store : stores()){
			if(path.length()>store.length()){
				if(path.substr(0,store.length())==store){
					return path.substr(store.length()+1);
				}
			}
		}
	}
	return (boost::filesystem::path("-")/path).string();
}

std::vector<Component::File> Component::list(const std::string& subdirectory){
	using namespace boost::filesystem;
	std::vector<File> files;
	std::string dir = boost::filesystem::path(path()).parent_path().string() + subdirectory;
	if(exists(dir) and is_directory(dir)){
		directory_iterator end ;
		for(directory_iterator iter(dir) ; iter != end ; ++iter){
			File file;
			file.name = iter->path().filename().string();
			if(is_regular_file(iter->status())) file.type = "f";
			else if(is_directory(iter->status())) file.type = "d";
			else file.type = "o";
			files.push_back(file);
		}
	}
	// Sort alphabetically
	std::sort(files.begin(),files.end(),File::by_name);
	return files;
}

Component& Component::destroy(void){
	boost::filesystem::path path_full = Component::path();
	if(boost::filesystem::exists(path_full)){
		boost::filesystem::remove_all(path_full);
	}
	return *this;
}

Component& Component::create(const std::string& path,const std::string& content){
	boost::filesystem::path path_full(Component::path(true));
	path_full /= path;
	if(!boost::filesystem::exists(path_full)){
		std::ofstream file(path_full.string());
		file<<content;
		file.close();
	}
	return *this;
}

Component& Component::write(const std::string& path,const std::string& content){
	boost::filesystem::path path_full(Component::path(true));
	path_full /= path;
	std::ofstream file(path_full.string());
	file<<content;
	file.close();
	return *this;
}

Component& Component::delete_(const std::string& path){
	boost::filesystem::path path_full(Component::path());
	path_full /= path;
	if(boost::filesystem::exists(path_full)){
		boost::filesystem::remove_all(path_full);
	}
	return *this;
}

Component& Component::read(const std::string& from){
	path(from);
	return *this;
}

Component& Component::write(const std::string& to){
	path(to);
	return *this;
}

}