
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2375; }

// ���������촦��
void create()
{
        set_name("����ʥ��");
        set_picid_1(6162);
        set_picid_2(6162);

        set_level(117);
        set_value(1000);
        set_max_lasting(25899);
        set("ap", 0);
        set("dp", 175);
        set("cp", 0);
        set("pp", 302);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ʥ��";
}
