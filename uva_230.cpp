    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    string str,author,title,command;
    pair < string, string > book;
    set < pair < string, string > > shelf;  
    char c_author[81],c_title[81],c_command[10];
    
    while(getline(cin,str))
    {
    if(str=="END") break;
    sscanf(str.c_str(),"\"%[^\"]\" by %[^\"]",c_title,c_author);
    author=string(c_author);
    title=string(c_title);
    book=make_pair(author,title);
    shelf.insert(book);
    }
    
    set < pair < string, string> > :: iterator it_shelf;
    map < string, int> book_serial;
    vector < string > shelf_vect;
    vector < bool > isBorrowed;
    set < int > returned;
    
    int i=0;
    for(it_shelf=shelf.begin();it_shelf != shelf.end();it_shelf++)
    {
    title=it_shelf->second;
    shelf_vect.push_back(title);
    book_serial.insert(make_pair(title,i));
    isBorrowed.push_back(false);
    i++;
    }
    
    while(getline(cin,str))
    {
    if(str=="END") break;
    if(str=="SHELVE"){
    for(set< int >:: iterator it=returned.begin();it != returned.end();it++)
    {
    int b= *it;
    if(!isBorrowed[b]){
    b--;
    while( b >  (-1)){
    if(!isBorrowed[b]){
    printf("Put \"%s\" after \"%s\"\n",shelf_vect[(*it)].c_str(),shelf_vect[b].c_str());
    break;
    }
    else b--;
    }
    if(b == (-1) ) printf("Put \"%s\" first\n",shelf_vect[(*it)].c_str());
    }
    }
    printf("END\n");
    returned.clear();
    }
    else {
    sscanf(str.c_str(),"%[^ ] \" %[^\"]",c_command,c_title);
    command=string(c_command);
    title=string(c_title);
    i = book_serial[title];
    if(command=="BORROW") isBorrowed[ i ] = true;
    else if(command=="RETURN") {
    isBorrowed[i] = false;
    returned.insert(i);
    }
    }
    }
    return 0;
    }