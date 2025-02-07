
private static int StoreOpen;
private static string StoreName = "�ӻ�̯";
private static mapping Store = ([ ]);           // ��Ʒ����
private static mapping Beast = ([ ]);           // �ٻ��޶�Ӧ��

// -------------------------------------------------------------

// ��������ȡ��Ʒ����
mapping get_store_dbase() { return copy(Store); }

// ��������ʼ����Ʒ����
void init_store_dbase() { Store = ([ ]); Beast = ([ ]); };

// -------------------------------------------------------------

// ��������ȡ��Ʒ����
int get_store( string key ) { return Store[key]; }

// ������������Ʒ����
int set_store( string key, int value ) 
{ 
        send_user( this_object(), "%c%c%d", 0x7b, to_int(key), value );
        return Store[key] = value; 
}

// ������ɾ����Ʒ����
void delete_store( string key ) 
{ 
        send_user( this_object(), "%c%c%d", 0x7b, to_int(key), -1 );
        map_delete(Store, key); 
}

// ��������ȡ��������
string get_store_name() { return StoreName; }

// ������������������
string set_store_name( string name ) 
{ 
        object me = this_object();

        if( sizeof(name) > 20 ) name = name[0..19];
        if( !CHECK_D->is_legal_store(me, name) ) return StoreName;
//      if( !is_chinese(name) ) return StoreName;

        if( StoreOpen && name != StoreName )    // ��̯ʱ��Ⱥ��
        {
                if( me->get_login_flag() > 1 ) send_user(me, "%c%c%s", 0x3d, 80, name);
                send_user( get_scene_object_2(me, USER_TYPE), "%c%c%d%s", 0x3d, 81, getoid(me), name );
        }
        return StoreName = name;
}

// �����������Ƿ��
int is_store_open() { return StoreOpen; }

// ������������
int open_store( int flag ) { return StoreOpen = flag; }

//��ȡ�ϼܳ���λ��
string get_store_beast_pos()
{
	int i;
	for(i=0;i<3;i++)
	{
		if ( Store[sprintf("%2d",100+i)] ) continue;
		return sprintf("%2d",100+i);
	}	
	return 0;
}

//��ȡ�ϼܳ���ID
string get_store_beast_id(string key) { return Beast[key]; }

//�趨�ϼܳ���ID
string set_store_beast_id(string key, string id) { return Beast[key] = id; }

//ɾ���ϼܳ���ID
void delete_store_beast_id(string key) { map_delete(Beast,key); }
