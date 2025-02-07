
inherit NPC;

private static int Level2 = 0;          // ѵ���ȼ�

private static int Front;               // ս������(1: ��, 2: ��)

private static int XX, YY;              // �ɵ�����

private static int DistanceX;           // ͬ���ߣؾ���

// �������Ƿ�ս��ս��
int is_comrade() { return 1; }

// -------------------------------------------------------------

// ��������ȡѵ���ȼ�
int get_level_2() { return Level2; }

// ����������ѵ���ȼ�
int set_level_2( int point ) { return Level2 = point; }

// ��������ȡս������
int get_front() { return Front; }

// ����������ս������
int set_front( int flag ) { return Front = flag; }

// ��������ȡ�ɣ�����
int get_xx() { return XX; }

// ���������þɣ�����
int set_xx( int point ) { return XX = point; }

// ��������ȡ�ɣ�����
int get_yy() { return YY; }

// ���������þɣ�����
int set_yy( int point ) { return YY = point; }

// ��������ȡͬ���ߣؾ���
int get_distance_x() { return DistanceX; }

// ����������ͬ���ߣؾ���
int set_distance_x( int point ) { return DistanceX = point; }

// -------------------------------------------------------------

// ��������������(ѭ��)
void heart_beat_loop( int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 ) { __FILE__ ->heart_beat_loop_callout( this_object(), effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8 ); }

// ��������������(ѭ��)(���߸���)
void heart_beat_loop_callout( object me, int effect1, int effect2, int effect3, int effect4, int effect5, int effect6, int effect7, int effect8 )    // ÿ���봦��
{
        object map, *char, npc;
        int id, x, y, i, size;

        NPC_EFFECT_D->into_effect(me, effect1, effect2, effect3, effect4, effect5, effect6, effect7, effect8);    // ��״����
        if( !me ) return;    // �����˳�

        if( me->is_send_position() )
        {
                if( objectp( map = get_map_object( get_z(me) ) ) )    // ��ȡս������
                {
                        x = get_x(me);  y = get_y(me);

                        if( abs( x - me->get_xx() ) > 1 || abs( y - me->get_yy() ) > 1 )    // �¾����� >1 ʱ�ط�����
                        {
                                me->set_xx(x);  me->set_yy(y);
                                npc = me->get_manager();  id = getoid(me);  

                                if( map->get_manager() == npc )    // ������
                                {
                                        char = map->get_user_dbase();
                                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 22, id, x, y );
                                }
                                else if( map->get_manager_2() == npc )    // ���ط�
                                {
                                        char = map->get_user_2_dbase();
                                        for( i = 0, size = sizeof(char); i < size; i ++ ) 
                                                if( objectp( npc = char[i] ) ) send_user( npc, "%c%c%d%w%w", 0x54, 22, id, x, y );
                                }
                        }
                }
        }

        if( me->add_heart_sec(1) % 8 == 0 ) NPC_HEART_D->heart_beat_8sec(me);    // ÿ���봦��
}

// ��������·����(����֮�е���)
void heart_beat_walk() { NPC_COMRADE_D->heart_beat_walk( this_object() ); }

// �������жϿ���ս��
int can_fight( object who ) { return NPC_COMRADE_D->can_fight( this_object(), who ); }

// ���������Խ���ս��
int can_be_fighted( object who ) { return NPC_COMRADE_D->can_be_fighted( this_object(), who ); }
