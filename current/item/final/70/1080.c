
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit WEAPON;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1042; }

// ���������촦��
void create()
{
        set_name("�׹�ȭ��");
        set_picid_1(7017);
        set_picid_2(7017);

        set_level(80);
        set_value(8000);
        set_max_lasting(14099);
        set("ap", 185);
        set("dp", 60);
        set("cp", 0);
        set("pp", 0);

        setup();

        set_weapon_type(UNARMED);
}

// ��������ȡ��������
int get_weapon_level() { return LEVEL_09; }

// ��������ȡ����
string get_desc()
{
        return "��ȭ����װ��";
}
