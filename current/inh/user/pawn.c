
// ���̴洢��Ʒ

private int Id;                         // ���̱�ʶ
private string Owner;                   // �������˱�ʶ
private mapping Pawn = ([ ]);           // �䵱��������

int restore();

// -------------------------------------------------------------

// ��������ȡ���̱�ʶ
int get_id() { return Id; }

// ���������õ��̱�ʶ
int set_id( int id ) { return Id = id; }

// ��������ȡ�û���ʶ
string get_owner() { return Owner; }

// �����������û���ʶ
int set_owner( string id )
{
        Owner = id;
        if( !user_exist(Owner) ) return 0;
        return restore();
}

// ��������ȡ�䵱����
mapping get_pawn() { return copy(Pawn); }

// ���������õ䵱����
void set_pawn( string key, string value ) 
{ 
        if( !mapp(Pawn) ) Pawn = ([ ]);
        Pawn[key] = value; 
}

// ������ɾ���䵱����
void delete_pawn( string key ) { map_delete(Pawn, key); }

// -------------------------------------------------------------

// ������ȡ�����ļ���
string get_save_file()
{
        if( !Owner || strlen(Owner) < 3 ) return 0;
        return sprintf( "data/%c/%c/%c/%s/pawn_%02d" SAVE_EXTENSION, Owner[0], Owner[1], Owner[2], Owner, Id );
}

// ������������������
int save()
{
        string file = get_save_file();
        if( !stringp(file) ) return 0;
        return save_object(file);
}

// ������������������
int restore()
{
        string file = get_save_file();
        if( !stringp(file) ) return 0;
        return restore_object(file);
}
