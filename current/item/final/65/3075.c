
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2188; }

// ���������촦��
void create()
{
        set_name("�໢��");
        set_picid_1(6542);
        set_picid_2(6542);

        set_level(75);
        set_value(9500);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 140);
        set("cp", 0);
        set("pp", 43);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�໢��";
}
