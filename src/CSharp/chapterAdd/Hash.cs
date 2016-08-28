using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class HashEntry
{
    public int key
    {
        get; set;
    }    

    public HashEntry(int k, int v)
    {
        key = k;
        val = v;
    }

    public int val
    {
        get;
        private set;
    }
}


public class HashMap
{
    private static int TABLE_SIZE = 100;
    private static int EntryDeleted = -1;
    private static int NoKeyFound = -2;


    HashEntry[] table;

    public HashMap()
    {
        table = new HashEntry[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = null;
    }

    public int get(int key)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != null && table[hash].key != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == null)
            return NoKeyFound;
        else
            return table[hash].val;
    }

    public void put(int key, int value)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != null && table[hash].key != EntryDeleted && table[hash].key != key)
            hash = (hash + 1) % TABLE_SIZE;
        table[hash] = new HashEntry(key, value);
    }

    public void delete(int key)
    {
        int hash = (key % TABLE_SIZE);
        while (table[hash] != null && table[hash].key != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != null)
        {
            table[hash].key = EntryDeleted;
            return;
        }
    }

}



namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {

            HashMap hm = new HashMap();
            hm.put(3, 3);
            hm.put(103, 4);
            hm.put(203, 5);
            hm.put(4, 44);

            int k = hm.get(4);
            int k1 = hm.get(203);
            hm.delete(203);
            int k2 = hm.get(203);
            int k3 = hm.get(4);
            int k4 = 10;

        }
    }
}
