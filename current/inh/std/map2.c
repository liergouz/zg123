
inherit "/inh/std/scene";

private static mapping mpHerb = ([ ]);          // ��ҩ����

// -------------------------------------------------------------

// ��������ȡ��ҩ����
mapping get_herb_dbase() { return copy(mpHerb); }

// ��������ȡ��ҩ���ݳߴ�
int sizeof_herb_dbase() { return sizeof(mpHerb); }

// �����������ҩ����(ˢ��ʱ)
void init_herb_dbase() { mpHerb = ([ ]); }

// ��������ȡ��ҩ����
int get_herb( int x, int y ) { return mpHerb[ sprintf("%d,%d", x, y) ]; }

// ���������ò�ҩ����
int set_herb( int x, int y, int value ) { return mpHerb[ sprintf("%d,%d", x, y) ] = value; }

// ��������Ӳ�ҩ����
int add_herb( int x, int y, int value )
{
        int old;

        if( !( old = get_herb(x, y) ) ) 
                return set_herb(x, y, value);
        else    return set_herb(x, y, old + value);
}

// -------------------------------------------------------------

// ����������֮ǰ����
void before_destruct()
{
        mapping officer;
        object map, *char, npc;
        string *key;
        int i, size;

        map = this_object();

        if( mapp( officer = map->get_npc_dbase() ) )
        {
                size = sizeof( key = keys(officer) );
                for( i = 0; i < size; i ++ ) if( objectp( npc = officer[ key[i] ] ) )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                }
        }

        if( arrayp( char = map->get_2("fish") ) )
        {
                for( i = 0, size = sizeof(char); i < size; i ++ ) if( objectp( npc = char[i] ) )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                }
        }

        if( arrayp( char = map->get_reset_dbase() ) )
        {
                for( i = 0, size = sizeof(char); i < size; i ++ ) if( objectp( npc = char[i] ) )
                {
                        npc->remove_from_scene();
                        destruct(npc);
                }
        }
}

//���볡������
void enter_scene(object who)
{
	QUEST_TIPS->enter_scene_tip(who,this_object());
}