
private mapping mpFamily = ([ ]);       // ͬ�����
private mapping mpCity = ([ ]);         // ͬ�����
private mapping mpOrg = ([ ]);          // ͬ�����

void add_family( object who ); 
void add_city( object who ); 
void add_org( object who ); 

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������촦��
void create() 
{ 
        object *user;
        int i, size;

        if( arrayp( user = users() ) )
                for( i = 0, size = sizeof(user); i < size; i ++ ) 
        {
                add_family( user[i] );  add_city( user[i] );  add_org( user[i] );
        }
}

// -------------------------------------------------------------

// ��������ȡ��������
mapping get_all_family() { return copy(mpFamily); }

// ��������ȡ���г���
mapping get_all_city() { return copy(mpCity); }

// ��������ȡ���а���
mapping get_all_org() { return copy(mpOrg); }

// -------------------------------------------------------------

// ��������ȡ�������
object *get_family( string name ) 
{ 
        if( undefinedp( mpFamily[name] ) || !arrayp( mpFamily[name] ) ) return ({ });
        if( sizeof( mpFamily[name] ) ) mpFamily[name] -= ({ 0 });
        return copy( mpFamily[name] ); 
}

// ��������ȡ�������
object *get_city( string name ) 
{ 
        if( undefinedp( mpCity[name] ) || !arrayp( mpCity[name] ) ) return ({ });
        if( sizeof( mpCity[name] ) ) mpCity[name] -= ({ 0 });
        return copy( mpCity[name] ); 
}

// ��������ȡ�������
object *get_org( string name ) 
{ 
        if( undefinedp( mpOrg[name] ) || !arrayp( mpOrg[name] ) ) return ({ });
        if( sizeof( mpOrg[name] ) ) mpOrg[name] -= ({ 0 });
        return copy( mpOrg[name] ); 
}

// �����������������
void add_family( object who ) 
{
        string name;

        if(     objectp(who) && userp(who) 
        &&      stringp( name = who->get_fam_name() ) && name != ""  )
        {
                if( undefinedp( mpFamily[name] ) || !arrayp( mpFamily[name] ) ) mpFamily[name] = ({ who });
                else if( member_array( who, mpFamily[name] ) == -1 ) mpFamily[name] += ({ who });
        }
}

// ���������ӳ������
void add_city( object who ) 
{
        string name;

        if(     objectp(who) && userp(who) 
        &&      stringp( name = who->get_city_name() ) && name != "" )
        {
                if( undefinedp( mpCity[name] ) || !arrayp( mpCity[name] ) ) mpCity[name] = ({ who });
                else if( member_array( who, mpCity[name] ) == -1 ) mpCity[name] += ({ who });
        }
}

// ���������Ӱ������
void add_org( object who ) 
{
        string name;

        if(     objectp(who) && userp(who) 
        &&      stringp( name = who->get_org_name() ) && name != "" && (who->get_org_position()>0) )
        {
                if( undefinedp( mpOrg[name] ) || !arrayp( mpOrg[name] ) ) mpOrg[name] = ({ who });
                else if( member_array( who, mpOrg[name] ) == -1 ) mpOrg[name] += ({ who });
        }
}

// �����������������
void sub_family( object who ) 
{
        string name;

        if(    !objectp(who) || !( name = who->get_fam_name() )
        ||      undefinedp( mpFamily[name] ) || !arrayp( mpFamily[name] ) ) return;

        if( sizeof( mpFamily[name] ) ) mpFamily[name] -= ({ who, 0 });
        if( !sizeof( mpFamily[name] ) ) map_delete( mpFamily, name );
}

// ���������ٳ������
void sub_city( object who ) 
{
        string name;

        if(    !objectp(who) || !( name = who->get_city_name() )
        ||      undefinedp( mpCity[name] ) || !arrayp( mpCity[name] ) ) return;

        if( sizeof( mpCity[name] ) ) mpCity[name] -= ({ who, 0 });
        if( !sizeof( mpCity[name] ) ) map_delete( mpCity, name );
}

// ���������ٰ������
void sub_org( object who ) 
{
        string name;

        if(    !objectp(who) || !( name = who->get_org_name() )
        ||      undefinedp( mpOrg[name] ) || !arrayp( mpOrg[name] ) ) return;

        if( sizeof( mpOrg[name] ) ) mpOrg[name] -= ({ who, 0 });
        if( !sizeof( mpOrg[name] ) ) map_delete( mpOrg, name );
}

// -------------------------------------------------------------

// ����������Ƶ��
void city_channel( string name, int id, string chat )
{
        if( undefinedp( mpCity[name] ) || !arrayp( mpCity[name] ) ) return;
        if( sizeof( mpCity[name] ) ) mpCity[name] -= ({ 0 });
        if( sizeof( mpCity[name] ) ) send_user( mpCity[name], "%c%c%d%s", 0x43, 3, id, chat );
}

// ����������Ƶ��
void org_channel( string name, int id, string chat )
{
        if( undefinedp( mpOrg[name] ) || !arrayp( mpOrg[name] ) ) return;
        if( sizeof( mpOrg[name] ) ) mpOrg[name] -= ({ 0 });
        if( sizeof( mpOrg[name] ) ) send_user( mpOrg[name], "%c%c%d%s", 0x43, 4, id, chat );
}

// ����������Ƶ��
void family_channel( string name, int id, string chat )
{
        if( undefinedp( mpFamily[name] ) || !arrayp( mpFamily[name] ) ) return;
        if( sizeof( mpFamily[name] ) ) mpFamily[name] -= ({ 0 });
        if( sizeof( mpFamily[name] ) ) send_user( mpFamily[name], "%c%c%d%s", 0x43, 5, id, chat );
}
