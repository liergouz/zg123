
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 7; }

// ��������Ʒ���
int get_fin_type() { return 1389; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(80);
        set_value(20000);
        set_max_lasting(20099);
        set("ap", 0);
        set("dp", 0);
        set("cp", 168);
        set("pp", 98);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
