
private static mapping Database = ([ ]);        // ��ͨ���ݼ�
private static mapping Database2 = ([ ]);       // ��ͨ���ݼ�(���ṹ)

private mapping SaveDatabase = ([ ]);           // �������ݼ�
private mapping SaveDbase2 = ([ ]);             // �������ݼ�(���ṹ)

private mixed _get( mapping db, string *key );
private mixed _set( mapping db, string *key, mixed value );
private int _delete( mapping db, string *key );

// -------------------------------------------------------------

// ��������ȡ��ͨ���ݼ�
mapping get_dbase() { return copy(Database); }

// ��������ȡ�������ݼ�
mapping get_save_dbase() { return copy(SaveDatabase); }

// ��������ȡ��ͨ���ݼ�(���ṹ)
mapping get_dbase_2() { return copy(Database2); }

// ��������ȡ�������ݼ�(���ṹ)
mapping get_save_dbase_2() { return copy(SaveDbase2); }

// ��������ʼ��ͨ���ݼ�
void init_dbase() { Database = ([ ]); }

// ��������ʼ�������ݼ�
void init_save_dbase() { SaveDatabase = ([ ]); }

// ��������ʼ��ͨ���ݼ�(���ṹ)
void init_dbase_2() { Database2 = ([ ]); }

// ��������ʼ�������ݼ�(���ṹ)
void init_save_dbase_2() { SaveDbase2 = ([ ]); }

// =============================================================

// ��������ȡ���ݼ�����
mixed get( string key ) { return Database[key]; }

// �������������ݼ�����
mixed set( string key, mixed value ) { return Database[key] = value; }

// ������������ݼ�����
mixed add( string key, mixed value )
{
        mixed old;

        if( !( old = get(key) ) ) 
                return set(key, value);
        else    return set(key, old + value);
}

// ������ɾ�����ݼ�����
void delete( string key ) { map_delete(Database, key); }

// -------------------------------------------------------------

// ��������ȡ�������ݼ�����
mixed get_save( string key ) { return SaveDatabase[key]; }

// ���������ô������ݼ�����
mixed set_save( string key, mixed value ) { return SaveDatabase[key] = value; }

// ��������Ӵ������ݼ�����
mixed add_save( string key, mixed value )
{
        mixed old;

        if( !( old = get_save(key) ) ) 
                return set_save(key, value);
        else    return set_save(key, old + value);
}

// ������ɾ���������ݼ�����
void delete_save( string key ) { map_delete(SaveDatabase, key); }

// =============================================================

// ��������ȡ���ݼ�����(���ṹ)
mixed get_2( string key )
{
        if( strchr( key, '.' ) == -1 ) return Database2[key];
        else return _get( Database2, explode( key, "." ) );
}

// �������������ݼ�����(���ṹ)
mixed set_2( string key, mixed value )
{
        if( strchr( key, '.' ) == -1 ) return Database2[key] = value;
        else return _set( Database2, explode( key, "." ), value );
}

// ������������ݼ�����(���ṹ)
mixed add_2( string key, mixed value )
{
        mixed old;

        if( !( old = get_2(key) ) ) 
                return set_2(key, value);
        else    return set_2(key, old + value);
}

// ������ɾ�����ݼ�����(���ṹ)
void delete_2( string key )
{
        if( strchr( key, '.' ) == -1 ) map_delete(Database2, key);
        else _delete( Database2, explode( key, "." ) );
}

// -------------------------------------------------------------

// ��������ȡ�������ݼ�����(���ṹ)
mixed get_save_2( string key )
{
        if( strchr( key, '.' ) == -1 ) return SaveDbase2[key];
        else return _get( SaveDbase2, explode( key, "." ) );
}

// ���������ô������ݼ�����(���ṹ)
mixed set_save_2( string key, mixed value )
{
        if( strchr( key, '.' ) == -1 ) return SaveDbase2[key] = value;
        else return _set( SaveDbase2, explode( key, "." ), value );
}

// ��������Ӵ������ݼ�����(���ṹ)
mixed add_save_2( string key, mixed value )
{
        mixed old;

        if( !( old = get_save_2(key) ) ) 
                return set_save_2(key, value);
        else    return set_save_2(key, old + value);
}

// ������ɾ���������ݼ�����(���ṹ)
void delete_save_2( string key )
{
        if( strchr( key, '.' ) == -1 ) map_delete(SaveDbase2, key);
        else _delete( SaveDbase2, explode( key, "." ) );
}

// -------------------------------------------------------------

// ��������ȡӳ����� db ������ key ������
private mixed _get( mapping db, string *key )
{
        mixed result = db;
        int i, size;

        for( i = 0, size = sizeof(key); i < size; i ++ )
        {
                result = result[ key[i] ];
                if( undefinedp(result) || !mapp(result) ) break;
        }
        return result;
}

// ����������ӳ����� db ������ key ������
private mixed _set( mapping db, string *key, mixed value )
{
        if( sizeof(key) == 0 ) 
                return db = value;
        else if( sizeof(key) == 1 ) 
                return db[ key[0] ] = value;
        else if( undefinedp( db[ key[0] ] ) || !mapp( db[ key[0] ] ) )
                db[ key[0] ] = ([ key[1] : 0 ]);

        return _set( db[ key[0] ], key[ 1..<1 ], value );
}

// ������ɾ��ӳ����� db ������ key ������
private int _delete( mapping db, string *key )
{
        int size = sizeof(key);

        if( size == 0 ) 
        {
                db = 0;
                return 1;
        }
        else if( size == 1 ) 
        {
                map_delete( db, key[0] );
                if( sizeof(db) == 0 ) db = 0;
                return 1;
        }
        else if( undefinedp( db[ key[0] ] ) || !mapp( db[ key[0] ] ) ) return 0;

        return _delete( db[ key[0] ], key[ 1..<1 ] );
}
