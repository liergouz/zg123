
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2287; }

// ���������촦��
void create()
{
        set_name("����ս��");
        set_picid_1(6182);
        set_picid_2(6182);

        set_level(120);
        set_value(12000);
        set_max_lasting(28899);
        set("ap", 0);
        set("dp", 261);
        set("cp", 0);
        set("pp", 185);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ս��";
}
