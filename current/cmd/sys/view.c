
// �����������
int main( object me, string arg )
{
        object *char, *npc, *npc2, *user;
        int size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        size = memory_info();
        tell_user( me, "�ڴ�: %d.%03d M    ����: %d", 
                size / 1048576, size % 1048576 * 1000 / 1048576, sizeof( objects() ) );
        tell_user( me, "����: %s  %d", get_load_average(), MAIN_D->get_absolute_random_number() );

        // char = objects( (: $1->is_char() && !clonep($1) :) );
        char = filter_array( livings(), (: $1->is_char() && !clonep($1) :) );
        npc = filter_array( livings(), (: $1->is_npc() && clonep($1) :) );
        user = filter_array( livings(), (: $1->is_user() && clonep($1) :) );
        tell_user( me, "����: %d �� %d�� �� ����(%d) �� �û�(%d)", 
                sizeof( livings() ), sizeof(char), sizeof(npc), sizeof(user) );

        char = heart_beats();    // objects( (: get_heart_beat($1) :) );    // ע�⣺get_heart_beat Ч��̫��
        npc = filter_array( char, (: $1->is_npc() && clonep($1) :) );
        npc2 = filter_array( npc, (: get_heart_idle($1) :) );
        user = filter_array( char, (: $1->is_user() && clonep($1) :) );
        tell_user( me, "����: %d �� ����(%d)����(%d) �� ���(%d)", sizeof(char), sizeof(npc), sizeof(npc2), sizeof(user) );

/*      char = objects( (: $1->get_enemy() :) );
        npc = filter_array( char, (: $1->is_npc() && clonep($1) :) );
        user = filter_array( char, (: $1->is_user() && clonep($1) :) );
        tell_user( me, "ս��: %d �� ����(%d) �� ���(%d)", sizeof(char), sizeof(npc), sizeof(user) );
*/
        tell_user( me, "�û�: %d  ���ߣ�%d / %d �� �ǣ�(%d) �� ���(%d)", 
                ID_D->get_max_id(), USER_D->sizeof_user(), sizeof_users(), USER_D->sizeof_gm(), USER_D->sizeof_player() );

	return 1;
}
