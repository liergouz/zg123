
#include <equip.h>

inherit WEAPON;

// ���������촦��
void create()
{
        set_name("�Ͼ�����");
        set_picid_1(7022);
        set_picid_2(7022);
        set_unit("˫");

        set_level(0);
        set_value(0);
        set_max_lasting(1099);
        set("ap", 20);
        set("!%", 6);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return 22; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
