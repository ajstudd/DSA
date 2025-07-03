// pseudo code

string final = "";
array arr = [ "cd ..", "cd parent", "cd admin", "cd ..", "cd /", "cd users" ]

    pwd // for present dir

        vector<string>
            st;

for (int i = 0; i < arr.size(); i++)
{
    if (arr[i] == "cd /")
    {
        reset the st;
    }
    if (arr[i] == "cd ..")
    {
        pop the last element;
    }
    if (
        arr[i] == "cd ..")
    {
        continue;
    }
    else
    {
        int size = arr[i].length();
        int name = substr(3, size);
        st.push_back(name);
    }
}
for (int i = 0; i < st.size(); i++)
{
    int dirName = st[i];
    final += dirName + "/";
}
cout << final;