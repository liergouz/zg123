
// ���������ɶ�������
void SAVE_BINARY() { }

/*
��Ǯ���� ����֣�� ������� ������ �������� ����ʩ�� �ײ��ϻ� ��κ�ս� ��л���� ��ˮ���
�����˸� �ɷ����� ³Τ���� ��ﻨ�� ����Ԭ�� ۺ��ʷ�� �����Ѧ �׺����� �����ޱ� ��������
����ʱ�� Ƥ���뿵 ����Ԫ�� ����ƽ�� �������� Ҧ�ۿ��� ��ë���� �ױ���� �Ʒ��ɴ� ̸��é��
�ܼ����� ��ף���� �������� ϯ����ǿ ��·¦Σ ��ͯ�չ� ÷ʢ�ֵ� �������� ���Ĳ��� �������
����֧�� �̹�¬Ī �������� �ɽ�Ӧ�� �����ڵ� �������� ������ʯ �޼�ť�� �����ϻ� ��½����
����춻� ��κ�ҷ� ���ഢ�� �������� ���θ��� �ڽ��͹� ����ɽ�� ������� ȫۭ���� ��������
�����ﱩ �������� ������� ��ղ���� Ҷ��˾�� ۬�輻�� ӡ�ް׻� ��̨�Ӷ� ���̼��� ׿������
�������� ���ܲ�˫ ��ݷ���� ̷������ ������� Ƚ��۪Ӻ �s�ɣ�� �ţ��ͨ �����༽ ۣ����ũ
�±�ׯ�� ����ֳ� Ľ����ϰ �°����� ������� ���θ��� �߾Ӻⲽ �������� ����Ŀ� ��»�ڶ�
Ź����� εԽ��¡ ʦ������ �˹����� �������� �Ǽ��Ŀ� ����ɳؿ ������� �������� ��󾣺�
����Ȩ�� ���Ỹ�� ��ٹ˾�� �Ϲ�ŷ�� �ĺ���� ���˶��� �����ʸ� ξ�ٹ��� �̨��ұ �������
���ڵ��� ̫������ �������� ��ԯ��� �������� ����Ľ�� �������� ˾ͽ˾�� ����˾�� �붽�ӳ�
����ľ �������� ������� ���ṫ�� �ذμй� �׸����� �����Ʒ� ��۳Ϳ�� �θɰ��� ��������
���ӹ麣 ����΢�� ��˧�ÿ� �������� �������� �������� ��Ĳ��٦ �����Ϲ� ī������ �갮��١
�����Ը� �ټ�����
*/

string *fname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��",
"��","ʩ","��","��","��","��","��","��","κ","��","��","��","л","��","�","��","��","��","��","��",
"³","Τ","��","��","��","��","��","Ԭ","��","��","ʷ","��","�","Ѧ","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��","��","Ф","Ҧ","��","��","ë","��","�","��",
"��","é","��","��","��","ף","��","��","��","��","��","��","ͯ","��","��","÷","��","��","��","��",
"��","��","��","��","��","��","��","��","��","¬","Ī","��","��","��","��","��","ʯ","��","��","��",
"��","½","��","��","��","��","��","��","��","ղ","��","Ҷ","��","��","��","̷","ţ","��","ׯ","��",
"��","��","��","ɳ","��",
// "˾��","�Ϲ�","ŷ��","����","ξ��","���","Ľ��","����","����","�Ϲ�",
});

int sizeof_fname = sizeof(fname);

string *criminal_name = ({    // �ط�

"�ϴ�","�϶�","����","����","����","����","����","�ϰ�","�Ͼ�",
"����","�ϵ���","�󵱼�","������","������",
"�Ϻ�","���","����","����",
"����","�����","������","������",
"����","������","������","������",
});

int sizeof_criminal_name = sizeof(criminal_name);

string *thief_name = ({    // ����

"С��","С��","С��","С��","С��",
"����","����","è��","�ö�",
});

int sizeof_thief_name = sizeof(thief_name);

string *banditi_name = ({    // ����

"�ϴ�","�϶�","����","����","����","����","����","�ϰ�","�Ͼ�",
"����","�ϵ���","�󵱼�","������","������",
"�Ϻ�","���","����","����",
"����","�����","������","������",
"����","������","������","������",
});

int sizeof_banditi_name = sizeof(banditi_name);

string *robber_name = ({    // ���

"�ϴ�","�϶�","����","����","����","����","����","�ϰ�","�Ͼ�",
"����","�ϵ���","�󵱼�","������","������",
"�Ϻ�","���","����","����",
"����","�����","������","������",
"����","������","������","������",
});

int sizeof_robber_name = sizeof(robber_name);

string *rascal_name = ({    // ���

"С��","С��","С��","С��","С��",
});

int sizeof_rascal_name = sizeof(rascal_name);

string *rascal_name_2 = ({    // ����

"����","�ϴ�","�϶�","����","����","����","����","����",
});

int sizeof_rascal_name_2 = sizeof(rascal_name_2);

// ��ȡ�ط�����
string get_criminal_name() { return fname[ random(sizeof_fname) ] + criminal_name[ random(sizeof_criminal_name) ]; }

// ��ȡ��������
string get_thief_name() { return fname[ random(sizeof_fname) ] + thief_name[ random(sizeof_thief_name) ]; }

// ��ȡ��������
string get_banditi_name() { return fname[ random(sizeof_fname) ] + banditi_name[ random(sizeof_banditi_name) ]; }

// ��ȡ�������
string get_robber_name() { return fname[ random(sizeof_fname) ] + robber_name[ random(sizeof_robber_name) ]; }

// ��ȡ�������
string get_rascal_name() { return fname[ random(sizeof_fname) ] + rascal_name[ random(sizeof_rascal_name) ]; }

// ��ȡ��������
string get_rascal_name_2() { return fname[ random(sizeof_fname) ] + rascal_name_2[ random(sizeof_rascal_name_2) ]; }
