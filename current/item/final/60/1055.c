
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2138; }

// ���������촦��
void create()
{
        set_name("�������ļ�");
        set_picid_1(6056);
        set_picid_2(6056);

        set_level(55);
        set_value(8000);
        set_max_lasting(19899);
        set("ap", 0);
        set("dp", 140);
        set("cp", 0);
        set("pp", 90);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�������ļ�";
}
