
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 2; }

// ��������Ʒ���
int get_fin_type() { return 2017; }

// ���������촦��
void create()
{
        set_name("����ͷ��");
        set_picid_1(6620);
        set_picid_2(6620);

        set_level(70);
        set_value(5500);
        set_max_lasting(14899);
        set("ap", 0);
        set("dp", 126);
        set("cp", 0);
        set("pp", 52);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����ͷ��";
}
