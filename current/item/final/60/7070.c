
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 2010; }

// ���������촦��
void create()
{
        set_name("��¶��");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(70);
        set_value(5500);
        set_max_lasting(14899);
        set("ap", 0);
        set("dp", 119);
        set("cp", 0);
        set("pp", 189);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��¶��";
}
